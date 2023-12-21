function findUniqueNumber(array) {
    // 配列を昇順にソート
    array.sort((a, b) => a - b);
  
    // 配列の先頭から順番に比較して、異なる数字が見つかったらそれを返す
    for (let i = 0; i < array.length - 1; i += 2) {
      if (array[i] !== array[i + 1]) {
        return array[i];
      }
    }
  
    // 最後の数字が異なる場合、最後の数字を返す
    return array[array.length - 1];
  }
  
  // テスト
  console.log(findUniqueNumber([1, 1, 5])); // 出力: 5
  console.log(findUniqueNumber([0, 1, 3, 1, 0])); // 出力: 3