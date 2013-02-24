CKEDITOR.plugins.add('vimeo',
{
    init: function (editor) {

        var pluginName = 'vimeo';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('Vimeo',
            {
                label: 'Vimeo',
                command: pluginName,
                icon: this.path + 'images/favicon.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
