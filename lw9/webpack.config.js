const path = require('path');
const ExtractTextPlugin = require('extract-text-webpack-plugin');

module.exports = {
    entry: {
        'index.css': [
            path.resolve(__dirname, 'src/view/menu/InsertView.css'),
            path.resolve(__dirname, 'src/view/menu/MenuView.css'),
        ],
        'index.js': [
            path.resolve(__dirname, 'src/index.js')
        ]
    },
    output: {
        filename: '[name]',
        path: path.resolve(__dirname, 'dist'),
    },
    module: {
        rules: [
            {
                test: /\.css$/,
                use: ExtractTextPlugin.extract({
                    fallback: 'style-loader',
                    use: 'css-loader'
                })
            },
        ],
    },
    plugins: [
        new ExtractTextPlugin("index.css"),
    ]
};