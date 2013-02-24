CKEDITOR.plugins.add('vuvox',
{
    init: function (editor) {

        var pluginName = 'vuvox';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('Vuvox',
            {
                label: 'Vuvox',
                command: pluginName,
                icon: this.path + 'images/favicon.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
