CKEDITOR.plugins.add('storify',
{
    init: function (editor) {

        var pluginName = 'storify';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('Storify',
            {
                label: 'Storify',
                command: pluginName,
                icon: this.path + 'images/favicon.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
