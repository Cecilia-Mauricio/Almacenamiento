const interruptorModel = require('../models/interruptores');

module.exports = {
 getById: async (req, res, next) =>{
  console.log(req.body);
  interruptorModel.findById(req.params.interruptorId, function(err, interruptorInfo){
   if (err) {
    next(err);
   } else {
    res.json({status:"success", message: "Interruptor found!!!", data:{interruptor: interruptorInfo}});
   }
  });
 },
getAll: async (req, res, next)  => {
  let interruptores = [];
  await interruptorModel.find({}, function(err, Interruptores){
  	if (err){
  		next(err);
  	} else{
  		for (let interruptor of Interruptores) {
  			interruptores.push({id: interruptor._id, inter: interruptor.inter, est: interruptor.est});
  		}
  		res.json({status:"success", message: "Interruptores list found!!!", data:{Interruptores: interruptores}}); 
  	}
   });
},
create: async(req, res, next) => {
  await interruptorModel.create(req.body, function (err, result) {
      if (err) 
       next(err);
      else
       res.json({status: "success", message: "Interruptor added successfully!!!", data: req.body});
      
    });
 },
 updateById: async (req, res, next) =>{
  interruptorModel.findByIdAndUpdate(req.params.interruptorId,{est:req.body.est} ,function(err, interruptorInfo){
   if (err) {
    next(err);
   } else {
    res.json({status:"success", message: "Interruptor updated successfully!!!", data:{interruptor: interruptorInfo}});
   }
  });
 },
}
