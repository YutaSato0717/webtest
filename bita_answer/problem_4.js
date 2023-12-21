function getSpiralPath(matrix) {
    const result = [];
    const rows = matrix.length;
    const cols = matrix[0].length;
  
    let startRow = 0,
      endRow = rows - 1,
      startCol = 0,
      endCol = cols - 1;
  
    while (startRow <= endRow && startCol <= endCol) {
      // 上から下に移動
      for (let i = startRow; i <= endRow; i++) {
        result.push(matrix[i][startCol]);
      }
      startCol++;
  
      // 左から右に移動
      for (let i = startCol; i <= endCol; i++) {
        result.push(matrix[endRow][i]);
      }
      endRow--;
  
      // 下から上に移動
      if (startCol <= endCol) {
        for (let i = endRow; i >= startRow; i--) {
          result.push(matrix[i][endCol]);
        }
        endCol--;
      }
  
      // 右から左に移動
      if (startRow <= endRow) {
        for (let i = endCol; i >= startCol; i--) {
          result.push(matrix[startRow][i]);
        }
        startRow++;
      }
    }
  
    return result;
  }
  
  // テスト
  const matrix = [
    [6, 2, 1],
    [5, 4, 9],
    [3, 8, 7],
  ];
  console.log(getSpiralPath(matrix)); // 出力: [6, 5, 3, 8, 7, 9, 1, 2, 4]
  