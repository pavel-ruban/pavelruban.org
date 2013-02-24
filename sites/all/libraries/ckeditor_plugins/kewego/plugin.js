CKEDITOR.plugins.add('kewego',
{
    init: function (editor) {

        var pluginName = 'kewego';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('Kewego',
            {
                label: 'Kewego',
                command: pluginName,
                icon: this.path + 'images/favicon.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
