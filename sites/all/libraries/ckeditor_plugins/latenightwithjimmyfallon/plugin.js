CKEDITOR.plugins.add('latenightwithjimmyfallon',
{
    init: function (editor) {

        var pluginName = 'latenightwithjimmyfallon';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('LateNightWithJimmyFallon',
            {
                label: 'Late Night With Jimmy Fallon',
                command: pluginName,
                icon: this.path + 'images/favicon.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
