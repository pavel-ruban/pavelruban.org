CKEDITOR.plugins.add('ina2',
{
    init: function (editor) {

        var pluginName = 'ina2';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('INA2',
            {
                label: 'INA Compatible Iphone',
                command: pluginName,
                icon: this.path + 'images/favicon.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
