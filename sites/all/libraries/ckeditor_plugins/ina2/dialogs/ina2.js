CKEDITOR.dialog.add('ina2', function (editor) {
    CKEDITOR.skins.load(editor, 'ina2');
    return {
        title: 'Vidéo INA - Compatible iphone',
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
					    html: '<p>' + 'Entrer l\'adresse url qui se trouve après le paramètre src dans "Exporter"' + '</p><p>' + 'Exemple : http://www.ina.fr/video/embed/1993060001005/1039610/0d438017c7aa2362b9796dc317150b5a/425/319/0' + '</p><br />'
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
            var src = data.url.replace(data.url, '[{ina2:'+ data.url +'}]');
			
            editor.insertText(src);

        }
    };
});
