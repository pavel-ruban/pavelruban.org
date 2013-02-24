CKEDITOR.plugins.add('iframe',
{
    init: function (editor) {

        var pluginName = 'iframe';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('Iframe',
            {
                label: 'Iframe',
                command: pluginName,
                icon: this.path + 'images/favicon.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
