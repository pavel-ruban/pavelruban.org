CKEDITOR.plugins.add('flickr',
{
    init: function (editor) {

        var pluginName = 'flickr';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('Flickr',
            {
                label: 'Flickr',
                command: pluginName,
                icon: this.path + 'images/favicon.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
