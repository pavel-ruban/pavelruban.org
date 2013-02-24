CKEDITOR.dialog.add('qualifio', function (editor) {
    CKEDITOR.skins.load(editor, 'qualifio');
    return {
        title: 'Iframe Qualifio',
        minWidth: 300,
        minHeight: 100,
        contents: [
			{
			    id: 'plugin_text',
			    label: '',
			    title: '',
			    expand: true,
			    padding: 0,
			    elements:
				[
					{
					    type: 'html',
					    html: '<p>' + 'Entrer l\'url exacte de votre Iframe qualifio' + '</p><p>' + 'Exemple : http://questionnaire.francetv.fr/09/v1.cfm?id=52A03EA4-5056-BE00-639F-457C38A56E36&style=1073&iframe=true" id="qualifio11188" width="580" height="900"' + '</p><br />'
					},
                    {
                        type: 'text',
                        id: 'url',
                        label: 'URL',
                        validate: CKEDITOR.dialog.validate.notEmpty('Please enter a valid Qualifio iframe webpage address.'),
                        required: true,
                        commit: function (data) {
                            data.url = this.getValue();
                        }
                    },
				]
			}
		],
        onOk: function () {
            // http://docs.cksource.com/ckeditor_api/symbols/CKEDITOR.dom.document.html#createElement
            var dialog = this,
				data = {};
			
			this.commitContent(data);
            var src = data.url.replace(data.url, '[{qualifio:'+ data.url +'}]');
			
            editor.insertText(src);

        }
    };
});
