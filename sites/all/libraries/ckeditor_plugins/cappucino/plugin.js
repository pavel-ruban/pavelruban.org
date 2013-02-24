CKEDITOR.plugins.add('cappucino',
{
    init: function (editor) {

        var pluginName = 'cappucino';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('Cappucino',
            {
                label: 'Cappucino',
                command: pluginName,
                icon: this.path + 'images/favicon.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
