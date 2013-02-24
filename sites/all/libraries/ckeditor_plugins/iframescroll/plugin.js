CKEDITOR.plugins.add('iframescroll',
{
    init: function (editor) {

        var pluginName = 'iframescroll';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('Iframescroll',
            {
                label: 'Iframescroll',
                command: pluginName,
                icon: this.path + 'images/favicon.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
