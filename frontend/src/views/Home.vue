<!--suppress ALL -->
<template>
    <div>
        <el-row :gutter="24" class="card">
            <el-col :span="10" :offset="7">
                <el-card class="box-card">
                    <div>
                        <h1>Data Structures and Algorithms</h1>
                    </div>
                </el-card>
            </el-col>
        </el-row>
        <el-row :gutter="24" class="card">
            <el-col :span="10" :offset="7">
                <el-card>
                    <div slot="header" class="card-header">
                        <span>实验介绍</span>
                    </div>
                    <div>
                        <p>本课程实践完成一个网上拍卖系统的实现，该系统共分五个部分，前四部分是必做的，最后一部分为选做。</p>
                        <p>详情参见任务说明书</p>
                    </div>
                </el-card>
            </el-col>
        </el-row>
    </div>
</template>

<script>
    export default {
        name: 'Home',
    }
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
    h1 {
        text-align: center;
    }

    .card {
        margin: 8px 0;
    }

    .card-header {
        text-align: center;
        font-size: 1.5rem;
    }
</style>
