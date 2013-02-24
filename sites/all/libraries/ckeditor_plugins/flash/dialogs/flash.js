CKEDITOR.dialog.add('flash', function (editor) {
    CKEDITOR.skins.load(editor, 'flash');
    return {
        title: 'Flash',
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
					    html: '<p>' + 'Entrer l\'adresse url de votre Flash' + '</p><p>' + 'Exemple : http://www.senat.fr/fileadmin/Fichiers/Images/evenement/senatoriales2011/carte_candidats/senatoriales-static.swf' + '</p><p>' + 'ou http://www.senat.fr/fileadmin/Fichiers/Images/evenement/senatoriales2011/carte_candidats/senatoriales-static.swf?w=640&h=360' + '</p><br />'
					},
                    {
                        type: 'text',
                        id: 'url',
                        label: 'URL',
                        validate: CKEDITOR.dialog.validate.notEmpty('Please enter a valid Flash video webpage address.'),
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
            var src = data.url.replace(data.url, '[{flash:'+ data.url +'}]');
			
            editor.insertText(src);

        }
    };
});