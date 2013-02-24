CKEDITOR.plugins.add('showtvbbc',
{
    init: function (editor) {

        var pluginName = 'showtvbbc';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('LateNightWithJoolsHolland',
            {
                label: 'Late Night with Jool’s Holland',
                command: pluginName,
                icon: this.path + 'images/favicon.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
