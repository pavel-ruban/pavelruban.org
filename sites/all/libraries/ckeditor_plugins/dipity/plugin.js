CKEDITOR.plugins.add('dipity',
{
    init: function (editor) {

        var pluginName = 'dipity';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('Dipity',
            {
                label: 'Dipity',
                command: pluginName,
                icon: this.path + 'images/favicon.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
