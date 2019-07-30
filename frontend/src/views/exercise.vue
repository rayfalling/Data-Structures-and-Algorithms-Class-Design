<!--suppress ALL -->
<template>
    <div>
        <el-row :gutter="20">
            <el-col :span="14" :offset="5">
                <el-card class="box-card">
                    <router-view/>
                </el-card>
            </el-col>
        </el-row>
    </div>
</template>

<script>
    export default {
        name: "exercise"
    }
</script>

<style scoped>

</style>