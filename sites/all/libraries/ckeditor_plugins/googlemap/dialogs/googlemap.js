CKEDITOR.dialog.add('googlemap', function (editor) {
    CKEDITOR.skins.load(editor, 'googlemap');
    return {
        title: 'GoogleMap',
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
					    html: '<p>' + 'Entrer l\'adresse url de votre GoogleMap' + '</p><p>' + 'Exemple : http://maps.google.fr/maps?f=q&source=s_q&hl=fr&geocode=&q=paris&aq=&sll=46.75984,1.738281&sspn=14.800841,33.815918&ie=UTF8&hq=&hnear=Paris,+%C3%8Ele-de-France&z=12&iwloc=A' + '</p><br />'
					},
                    {
                        type: 'text',
                        id: 'url',
                        label: 'URL',
                        validate: CKEDITOR.dialog.validate.notEmpty('Please enter a valid GoogleMap video webpage address.'),
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
            var src = data.url.replace(data.url, '[{'+ data.url +'}]');
			
            editor.insertText(src);

        }
    };
});