let orderDetails = {
    coffee: { count: 0, price: 480 },
    tea: { count: 0, price: 280 },
    milk: { count: 0, price: 180 },
    coke: { count: 0, price: 190 },
    beer: { count: 0, price: 580 },
  };
  let totalCount = 0;
  let totalPrice = 0;
  
  function addToCart(id, price) {
    orderDetails[id].count++;
    totalCount++;
    totalPrice += price;
  
    
    document.getElementById(`${id}-count`).textContent = orderDetails[id].count;
  
    updateOrderSummary();
  }
  
  function updateOrderSummary() {
    document.getElementById('count').textContent = totalCount;
    document.getElementById('price').textContent = `${totalPrice}`;
  }
  
  