console.log("CC");

const express = require("express");
const app = express();


app.get("/hello",(request,response)=>{
    response.send("<p>Hello World</p>");
});

app.listen(8000,()=>{
    console.log("Serveur lancé sur localhost:8000");
});

// const users = ["David","Louis","Théo"];

// app.get("/user",(req,res)=>{
//     res.send(users[0]);
// })


const product = {
    id : 3,
    name : "Nike Air",
    price : 99
};

app.get("/product",(req,res)=>{
    res.json(product);
})




const products = [
    {
        id : 1,
        name : "Puma taille 42",
        price : 67
    },
    {
        id : 2,
        name : "Adidias sport",
        price : 102
    },
    {
        id : 3,
        name : "Nike Air",
        price : 99
    },
];

app.get("/all_products",(req,res)=>{
    res.json(products);
})






// const users = [
//     {
//         name : "theo",
//         lastname : "dupont",
//         age : 25
//     },
//     {
//         name : "Mattieu",
//         lastname : "Dupuit",
//         age : 19
//     },
//     {
//         name : "Billy",
//         lastname : "Elliot",
//         age : 12
//     }
// ];

// app.get("/all_users", (req,res) =>{
//     res.json(users);
// });


const users = ["David","Louis","Théo"];

// Ajout d'une nouvelle route
app.get("/user/:id",(request,response)=>{
    const userId = request.params.id;
    response.json(users[userId]);
});