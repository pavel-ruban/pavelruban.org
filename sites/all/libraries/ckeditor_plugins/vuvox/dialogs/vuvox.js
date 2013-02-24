CKEDITOR.dialog.add('vuvox', function (editor) {
    CKEDITOR.skins.load(editor, 'vuvox');
    return {
        title: 'Vidéo Vuvox',
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
					    html: '<p>' + 'Entrer l\'adresse url de votre vidéo Vuvox' + '</p><p>' + 'Exemple : http://www.vuvox.com/collage_express/collage.swf?collageID=03a3bf3b6f' + '</p><br />'
					},
                    {
                        type: 'text',
                        id: 'url',
                        label: 'URL',
                        validate: CKEDITOR.dialog.validate.notEmpty('Please enter a valid Vuvox video webpage address.'),
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
            var src = data.url.replace(data.url, '[{'+ data.url +'}]');
			
            editor.insertText(src);

        }
    };
});