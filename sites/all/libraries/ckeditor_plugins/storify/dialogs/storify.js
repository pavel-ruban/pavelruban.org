CKEDITOR.dialog.add('storify', function (editor) {
    CKEDITOR.skins.load(editor, 'storify');
    return {
        title: 'Vidéo Storify',
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
					    html: '<p>' + 'Entrer l\'adresse url de votre vidéo Storify' + '</p><p>' + 'Exemple : http://storify.com/FirestormSol/anonymous-claims-responsibility-for-oppayback' + '</p><br />'
					},
                    {
                        type: 'text',
                        id: 'url',
                        label: 'URL',
                        validate: CKEDITOR.dialog.validate.notEmpty('Please enter a valid Storify video webpage address.'),
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
            var src = data.url.replace(data.url, '[{storify:'+ data.url +'}]');
			
            editor.insertText(src);

        }
    };
});