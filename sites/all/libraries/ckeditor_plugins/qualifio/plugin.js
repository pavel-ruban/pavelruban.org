CKEDITOR.plugins.add('qualifio',
{
    init: function (editor) {

        var pluginName = 'qualifio';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('Qualifio',
            {
                label: 'Qualifio',
                command: pluginName,
                icon: this.path + 'images/favicon.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
