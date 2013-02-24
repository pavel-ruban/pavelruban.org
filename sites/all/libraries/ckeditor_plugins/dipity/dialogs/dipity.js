CKEDITOR.dialog.add('dipity', function (editor) {
    CKEDITOR.skins.load(editor, 'dipity');
    return {
        title: 'Biographie Dipity',
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
					    html: '<p>' + 'Entrer l\'adresse url de votre biographie Dipity' + '</p><p>' + 'Exemple : http://www.dipity.com/timeline/Michael_Jackson' + '</p><br />'
					},
                    {
                        type: 'text',
                        id: 'url',
                        label: 'URL',
                        validate: CKEDITOR.dialog.validate.notEmpty('Please enter a valid Dipity video webpage address.'),
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
            var src = data.url.replace(data.url, '[{dipity:'+ data.url +'}]');
			
            editor.insertText(src);

        }
    };
});