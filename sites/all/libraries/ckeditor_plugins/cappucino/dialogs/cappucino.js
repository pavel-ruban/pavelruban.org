CKEDITOR.dialog.add('cappucino', function (editor) {
    CKEDITOR.skins.load(editor, 'cappucino');
    return {
        title: 'Vidéo Cappucino',
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
					    html: '<p>' + 'Entrer l\'adresse url de votre vidéo Cappucino' + '</p><p>' + 'Exemple : manuel_tls_extrait_1_20110531_273_01062011003324_F3' + '</p><br />'
					},
                    {
                        type: 'text',
                        id: 'url',
                        label: 'URL',
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
            var src = data.url.replace(data.url, '[{cappuccino:'+ data.url +'}]');
			
            editor.insertText(src);

        }
    };
});