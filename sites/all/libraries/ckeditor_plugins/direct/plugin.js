CKEDITOR.plugins.add('direct',
{
    init: function (editor) {

        var pluginName = 'direct';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('Direct',
            {
                label: 'Direct',
                command: pluginName,
                icon: this.path + 'images/favicon.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
