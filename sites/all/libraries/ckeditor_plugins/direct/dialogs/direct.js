CKEDITOR.dialog.add('direct', function (editor) {
    CKEDITOR.skins.load(editor, 'direct');
    return {
        title: 'Vidéo Direct',
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
					    html: '<p>' + 'Entrer l\'adresse url de votre vidéo Direct' + '</p><p>' + 'Exemple par chaînes : france2, france3, france4, franceo' + '</p><p>' + 'Par régions : guadeloupe, miquelon, ect...' + '</p><p>' + 'Par direct hors antenne : otil1, otil2, otil3' + '</p><br />'
					},
                    {
                        type: 'text',
                        id: 'url',
                        label: 'URL',
                        validate: CKEDITOR.dialog.validate.notEmpty('Please enter a valid Direct video webpage address.'),
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
            var src = data.url.replace(data.url, '[{direct:'+ data.url +'}]');
			
            editor.insertText(src);

        }
    };
});