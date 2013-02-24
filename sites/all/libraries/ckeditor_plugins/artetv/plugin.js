CKEDITOR.plugins.add('artetv',
{
    init: function (editor) {

        var pluginName = 'artetv';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('ArteTV',
            {
                label: 'Arte TV',
                command: pluginName,
                icon: this.path + 'images/favicon.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
