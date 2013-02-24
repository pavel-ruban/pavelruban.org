CKEDITOR.dialog.add('artetv', function (editor) {
    CKEDITOR.skins.load(editor, 'artetv');
    return {
        title: 'Vidéo Arte TV',
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
					    html: '<p>' + 'Entrer l\'url exacte de votre vidéo Arte TV' + '</p><p>' + 'Exemple : http://videos.arte.tv/fr/videos/syrie_onu_pourquoi_la_russie_fait_elle_blocage_-6541278.html' + '</p><br />'
					},
                    {
                        type: 'text',
                        id: 'url',
                        label: 'URL',
                        validate: CKEDITOR.dialog.validate.notEmpty('Please enter a valid Arte TV video webpage address.'),
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
            var src = data.url.replace(data.url, '[{artetv:'+ data.url +'}]');
			
            editor.insertText(src);

        }
    };
});
