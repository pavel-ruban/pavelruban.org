CKEDITOR.plugins.add('coveritlive',
{
    init: function (editor) {

        var pluginName = 'coveritlive';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('CoverItLive',
            {
                label: 'CoverItLive',
                command: pluginName,
                icon: this.path + 'images/favicon.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
