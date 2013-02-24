CKEDITOR.dialog.add('showtvbbc', function (editor) {
    CKEDITOR.skins.load(editor, 'showtvbbc');
    return {
        title: 'Vidéo Show TV BBC',
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
					    html: '<p>' + 'Entrer l\'adresse url de votre vidéo Show TV BBC' + '</p><p>' + 'Exemple : http://www.bbc.co.uk/later/#p00m657k' + '</p><br />'
					},
                    {
                        type: 'text',
                        id: 'url',
                        label: 'URL',
                        validate: CKEDITOR.dialog.validate.notEmpty('Please enter a valid Show TV BBC video webpage address.'),
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
            var src = data.url.replace(data.url, '[{showtvbbc:'+ data.url +'}]');
			
            editor.insertText(src);

        }
    };
});