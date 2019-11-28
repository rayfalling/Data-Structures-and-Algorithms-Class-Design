<!--suppress ALL -->
<template>
    <div id="app">
        <el-container>
            <el-header class="el-header-menu">
                <el-menu mode="horizontal" default-active="1" background-color="#545c64"
                         text-color="#fff" active-text-color="#ffd04b" :router="true">
                    <el-menu-item index="1" route="/">
                        <i class="el-icon-menu"></i>
                        <span slot="title">首页</span>
                    </el-menu-item>
                    <el-menu-item index="2" route="/exercise/login">
                        <i class="el-icon-cpu"></i>
                        <span slot="title">实验</span>
                    </el-menu-item>
                </el-menu>
            </el-header>
            <el-main>
                <router-view/>
            </el-main>
            <el-footer class="el-footer-bg">
                <p>看不过去旧版的课设,随手重新写了一个</p>
            </el-footer>
        </el-container>
    </div>
</template>

<style>
    #app {
        font-family: 'Avenir', Helvetica, Arial, sans-serif;
        -webkit-font-smoothing: antialiased;
        -moz-osx-font-smoothing: grayscale;
        color: #2c3e50;
    }

    body {
        margin: 0;
    }

    .el-header-menu {
        padding: 0;
        top: 0;
    }

    .el-footer-bg {
        text-align: center;
        background: #545c64;
        width: 100%;
        height: 100%;
        color: #fefefe;
        padding: 0;
        position: fixed;
        bottom: 0;
    }
</style>

<script>
    export default {
        name: 'App',
    }
</script>
