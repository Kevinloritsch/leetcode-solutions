-- Last updated: 12/27/2025, 3:44:30 PM
SELECT Product.product_name, Sales.year, Sales.price FROM SALES
LEFT JOIN Product ON
Sales.product_id=Product.product_id;