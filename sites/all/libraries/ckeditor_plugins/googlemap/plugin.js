CKEDITOR.plugins.add('googlemap',
{
    init: function (editor) {

        var pluginName = 'googlemap';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('googleMap',
            {
                label: 'GoogleMap',
                command: pluginName,
                icon: this.path + 'images/favicon.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
