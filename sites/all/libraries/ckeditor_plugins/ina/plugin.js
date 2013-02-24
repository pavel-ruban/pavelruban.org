CKEDITOR.plugins.add('ina',
{
    init: function (editor) {

        var pluginName = 'ina';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('INA',
            {
                label: 'INA',
                command: pluginName,
                icon: this.path + 'images/favicon.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
