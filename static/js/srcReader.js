// <pre><code>にsrc属性を追加
// <head>でjQueryを呼ぶことに注意

// DOMを読み込むまで動作しない
$( function() {
    $('pre code').each( function(index, codeTag) {
        var obj = $(this);
        // srcがあるか
        if(typeof obj.attr('src') !== "undefined") {
            // URL取得
            var url = obj.attr('src');
            // URLからコード取得
            $.get(url, function(code) {
                // 書き換え
                obj.text(code);
                // ハイライト
                hljs.highlightBlock(codeTag);
            });
        }
    });
});
