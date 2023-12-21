function shortest(str) {
    // 文字列をスペースで分割して各単語を配列に入れる
    const words = str.split(' ');
  
    let shortestLength = words[0].length;
  
    // 各単語の長さを比較して最短長を更新
    for (let i = 1; i < words.length; i++) {
      const currentLength = words[i].length;
      if (currentLength < shortestLength) {
        shortestLength = currentLength;
      }
    }

    return shortestLength;
  }
  
  // テスト
  console.log(shortest('red blue yellow green')); // 出力: 3
  