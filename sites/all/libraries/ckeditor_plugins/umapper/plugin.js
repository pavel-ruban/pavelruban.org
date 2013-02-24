CKEDITOR.plugins.add('umapper',
{
    init: function (editor) {

        var pluginName = 'umapper';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('Umapper',
            {
                label: 'Umapper',
                command: pluginName,
                icon: this.path + 'images/favicon.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
