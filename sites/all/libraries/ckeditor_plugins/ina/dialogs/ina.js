CKEDITOR.dialog.add('ina', function (editor) {
    CKEDITOR.skins.load(editor, 'ina');
    return {
        title: 'Vidéo INA',
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
					    html: '<p>' + 'Entrer l\'adresse url de votre vidéo INA' + '</p><p>' + 'Exemple : http://www.ina.fr/video/ticket/CAB95041359/937183/30264cfded993319ee16653c4eb6c359' + '</p><br />'
					},
                    {
                        type: 'text',
                        id: 'url',
                        label: 'URL',
                        validate: CKEDITOR.dialog.validate.notEmpty('Please enter a valid INA video webpage address.'),
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
            var src = data.url.replace(data.url, '[{ina:'+ data.url +'}]');
			
            editor.insertText(src);

        }
    };
});