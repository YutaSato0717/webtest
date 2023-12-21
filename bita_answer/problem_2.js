function format(str) {
    // 空文字列の場合はそのまま返す
    let NewStr = str[0];
  
    // 連続する重複した文字を取り除いて新しい文字列に追加
    for (let i = 1; i < str.length; i++) {
      if (str[i] !== str[i - 1]) {
        NewStr += str[i];
      }
    }

    return NewStr;
  }
  
  // テスト
  console.log(format('abbccccaabc')); // 出力: abcabc
  console.log(format('bbitaaa')); // 出力: bita
  console.log(format('yyyyutaaaa'));//出力: yuta