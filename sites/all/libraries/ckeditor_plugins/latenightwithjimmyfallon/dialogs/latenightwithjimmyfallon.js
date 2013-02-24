CKEDITOR.dialog.add('latenightwithjimmyfallon', function (editor) {
    CKEDITOR.skins.load(editor, 'latenightwithjimmyfallon');
    return {
        title: 'Vidéo Late night with Jimmy Fallon',
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
					    html: '<p>' + 'Entrer l\'identifiant de votre vidéo Late night with Jimmy Fallon, il se trouve après \'?vid=\'' + '</p><p>' + 'Exemple : http://www.nbc.com/assets/video/widget/widget.html?vid=<b>1388766</b>&w=512&h=347' + '</p><br />'
					},
                    {
                        type: 'text',
                        id: 'url',
                        label: 'Identifiant',
                        validate: CKEDITOR.dialog.validate.notEmpty('Please enter a valid Cappucino video webpage address.'),
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
            var src = data.url.replace(data.url, '[{latenightwithjimmyfallon:'+ data.url +'}]');
			
            editor.insertText(src);

        }
    };
});
