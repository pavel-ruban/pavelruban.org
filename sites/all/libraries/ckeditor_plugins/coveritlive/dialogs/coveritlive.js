CKEDITOR.dialog.add('coveritlive', function (editor) {
    CKEDITOR.skins.load(editor, 'coveritlive');
    return {
        title: 'CoverItLive',
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
					    html: '<p>' + 'Entrer l\'identifiant de votre CoverItLive' + '</p><p>' + 'Exemple : 206517199d' + '</p><br />'
					},
                    {
                        type: 'text',
                        id: 'url',
                        label: 'Identifiant',
                        validate: CKEDITOR.dialog.validate.notEmpty('Please enter a valid CoverItLive video webpage address.'),
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
            var src = data.url.replace(data.url, '[{coveritlive:'+ data.url +'}]');
			
            editor.insertText(src);

        }
    };
});