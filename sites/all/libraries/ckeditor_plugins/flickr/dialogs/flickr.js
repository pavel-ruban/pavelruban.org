CKEDITOR.dialog.add('flickr', function (editor) {
    CKEDITOR.skins.load(editor, 'flickr');
    return {
        title: 'Diaporama Flickr',
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
					    html: '<p>' + 'Il est impossible d\'utiliser l\'adresse suivante pour générer un diaporama !</p><p>http://www.flickr.com/photos/max_castellazzi/5780278849</p><p>Il nous faut absolument l\'ID_USER du compte Flickr. Voici un outil pour l\'obtenir : http://idgettr.com</p><br />' + '<p> Exemple : 52485778@N08.' + '</p><p> Exemple pour un album spécifique : 52485778@N08/72157628386277513 </p><br />'
					},
                    {
                        type: 'text',
                        id: 'url',
                        label: 'Diaporama',
                        validate: CKEDITOR.dialog.validate.notEmpty('Please enter a valid Flickr video webpage address.'),
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
            var src = data.url.replace(data.url, '[{flickr:'+ data.url +'}]');
			
            editor.insertText(src);

        }
    };
});