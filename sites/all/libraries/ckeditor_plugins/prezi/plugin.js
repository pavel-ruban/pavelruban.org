CKEDITOR.plugins.add('prezi',
{
    init: function (editor) {

        var pluginName = 'prezi';

        editor.addCommand(pluginName, new CKEDITOR.dialogCommand(pluginName));
        editor.ui.addButton('Prezi',
            {
                label: 'Prezi',
                command: pluginName,
                icon: this.path + 'images/prezi.png'
            });

            CKEDITOR.dialog.add(pluginName, this.path + 'dialogs/' + pluginName + '.js');


    }
});
