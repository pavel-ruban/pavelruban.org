CKEDITOR.plugins.add('flash',
{
    init: function (editor) {

        var pluginName = 'flash';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('Flash',
            {
                label: 'Flash',
                command: pluginName,
                icon: this.path + 'images/favicon.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
