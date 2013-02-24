CKEDITOR.plugins.add('soundcloud',
{
    init: function (editor) {

        var pluginName = 'soundcloud';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('SoundCloud',
            {
                label: 'SoundCloud',
                command: pluginName,
                icon: this.path + 'images/favicon.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
