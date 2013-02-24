CKEDITOR.dialog.add('umapper', function (editor) {
    CKEDITOR.skins.load(editor, 'umapper');
    return {
        title: 'Umapper',
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
					    html: '<p>' + 'Entrer l\'adresse url Umapper' + '</p><p>' + 'Exemple : http://www.umapper.com/maps/view/id/119953/' + '</p><p>' + 'ou http://www.umapper.com/maps/view/id/119953' + '</p><br />'
					},
                    {
                        type: 'text',
                        id: 'url',
                        label: 'URL',
                        validate: CKEDITOR.dialog.validate.notEmpty('Please enter a valid Umapper webpage address.'),
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
            var src = data.url.replace(data.url, '[{umapper:'+ data.url +'}]');
			
            editor.insertText(src);

        }
    };
});