CKEDITOR.plugins.add('dailymotion',
{
    init: function (editor) {

        var pluginName = 'dailymotion';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('DailyMotion',
            {
                label: 'DailyMotion',
                command: pluginName,
                icon: this.path + 'images/favicon.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
