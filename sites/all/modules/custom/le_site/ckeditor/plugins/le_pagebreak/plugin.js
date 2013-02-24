/*
 Copyright (c) 2003-2012, CKSource - Frederico Knabben. All rights reserved.
 For licensing, see LICENSE.html or http://ckeditor.com/license
 */

/**
 * @file Horizontal Page Break
 */

// Register a plugin named "le_pagebreak".
CKEDITOR.plugins.add('le_pagebreak',
  {
    init:function (editor) {
      // Register the command.
      editor.addCommand('le_pagebreak', CKEDITOR.plugins.le_pagebreakCmd);

      // Register the toolbar button.
      editor.ui.addButton('le_pagebreak',
        {
          label:editor.lang.le_pagebreak,
          command:'le_pagebreak'
        });

      var cssStyles = [
        '{' ,
        'background: url(' + CKEDITOR.getUrl(this.path + 'images/pagebreak.gif') + ') no-repeat center center;' ,
        'clear: both;' ,
        'width:100%; _width:99.9%;' ,
        'border-top: #999999 1px dotted;' ,
        'border-bottom: #999999 1px dotted;' ,
        'padding:0;' ,
        'height: 5px;' ,
        'cursor: default;' ,
        '}'
      ].join('').replace(/;/g, ' !important;');	// Increase specificity to override other styles, e.g. block outline.

      // Add the style that renders our placeholder.
      editor.addCss('div.cke_le_pagebreak' + cssStyles);

      // Opera needs help to select the page-break.
      CKEDITOR.env.opera && editor.on('contentDom', function () {
        editor.document.on('click', function (evt) {
          var target = evt.data.getTarget();
          if (target.is('div') && target.hasClass('cke_le_pagebreak'))
            editor.getSelection().selectElement(target);
        });
      });
    },

    afterInit:function (editor) {
      var label = editor.lang.le_pagebreakAlt;

      // Register a filter to displaying placeholders after mode change.
      var dataProcessor = editor.dataProcessor,
        dataFilter = dataProcessor && dataProcessor.dataFilter,
        htmlFilter = dataProcessor && dataProcessor.htmlFilter;

      if (htmlFilter) {
        htmlFilter.addRules(
          {
            attributes:{
              'class':function (value, element) {
                var className = 'le-pagebreak';
                element.children.length = 0;

                return className;
              }
            }
          }, 5);
      }

      if (dataFilter) {
        dataFilter.addRules(
          {
            elements:{
              div:function (element) {
                var attributes = element.attributes,
                  style = attributes && attributes.style,
                  child = style && element.children.length == 1 && element.children[ 0 ],
                  childStyle = child && ( child.name == 'span' ) && child.attributes.style;

                if (childStyle && ( /page-break-after\s*:\s*always/i ).test(style) && ( /display\s*:\s*none/i ).test(childStyle)) {
                  attributes.contenteditable = "false";
                  attributes[ 'class' ] = "cke_le_pagebreak";
                  attributes[ 'data-cke-display-name' ] = "le_pagebreak";
                  attributes[ 'aria-label' ] = label;
                  attributes[ 'title' ] = label;

                  element.children.length = 0;
                }
              }
            }
          });
      }
    },

    requires:[ 'fakeobjects' ]
  });

CKEDITOR.plugins.le_pagebreakCmd =
{
  exec:function (editor) {
    var label = editor.lang.le_pagebreakAlt;

    // Create read-only element that represents a print break.
    var le_pagebreak = CKEDITOR.dom.element.createFromHtml(
      '<div class="cke_le_pagebreak"></div>', editor.document);

    var ranges = editor.getSelection().getRanges(true);

    editor.fire('saveSnapshot');

    for (var range, i = ranges.length - 1; i >= 0; i--) {
      range = ranges[ i ];

      if (i < ranges.length - 1)
        le_pagebreak = le_pagebreak.clone(true);

      range.splitBlock('p');
      range.insertNode(le_pagebreak);
      if (i == ranges.length - 1) {
        var next = le_pagebreak.getNext();
        range.moveToPosition(le_pagebreak, CKEDITOR.POSITION_AFTER_END);

        // If there's nothing or a non-editable block followed by, establish a new paragraph
        // to make sure cursor is not trapped.
        if (!next || next.type == CKEDITOR.NODE_ELEMENT && !next.isEditable())
          range.fixBlock(true, editor.config.enterMode == CKEDITOR.ENTER_DIV ? 'div' : 'p');

        range.select();
      }
    }

    editor.fire('saveSnapshot');
  }
};
