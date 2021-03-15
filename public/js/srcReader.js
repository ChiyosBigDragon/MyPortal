// <pre><code>にsrc属性を追加
// <pre><code>に折りたたみ機能を追加
// <head>でjQueryを呼ぶことに注意

// DOMを読み込むまで動作しない
$(function() {
    $('.SyntaxHighlight').each(function(index, codeTag) {
		var textArea = $('div', this);
		var codeArea = $('pre code', this);
		// src追加
		codeArea.each( function(index, codeTag) {
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
		// 折りたたみ
		textArea.on('click', function() {
			var txt = $(this).text();
			if(txt == "[展開する]") {
				$(this).text("[折りたたむ]");
				codeArea.css('max-height', 'none');
			} else {
				$(this).text("[展開する]");
				codeArea.css('max-height', '300px');
			}
	   	});
    });
});
