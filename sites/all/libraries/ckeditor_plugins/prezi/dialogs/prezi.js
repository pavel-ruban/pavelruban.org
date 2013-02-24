CKEDITOR.dialog.add('prezi', function (editor) {
    CKEDITOR.skins.load(editor, 'prezi');
    return {
        title: 'Présentation Prezi',
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
					    html: '<p>' + 'Entrez l\'identifiant de votre présentation Prezi' + '</p><p>' + 'Exemple : xi4gxdi3p9qf' + '</p><br />'
					},
                    {
                        type: 'text',
                        id: 'url',
                        label: 'URL',
                        validate: CKEDITOR.dialog.validate.notEmpty('Please enter a valid Prezi id.'),
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
            var src = data.url.replace(data.url, '[{prezi:'+ data.url +'}]');
			
            editor.insertText(src);

        }
    };
});
