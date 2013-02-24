CKEDITOR.plugins.add('livewebarte',
{
    init: function (editor) {

        var pluginName = 'livewebarte';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('LivewebArte',
            {
                label: 'Liveweb Arte',
                command: pluginName,
                icon: this.path + 'images/favicon.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
