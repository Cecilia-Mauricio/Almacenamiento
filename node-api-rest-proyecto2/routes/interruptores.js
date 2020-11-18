const express = require('express');
const router = express.Router();
const interruptorContoller = require('../api/controllers/interruptores');
router.get('/', interruptorContoller.getAll);
router.post('/', interruptorContoller.create);
router.get('/:interruptorId', interruptorContoller.getById);
router.post('/:interruptorId', interruptorContoller.updateById);
module.exports = router;
